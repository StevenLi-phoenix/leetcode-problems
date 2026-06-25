// gen-readme — reads problems/ + difficulty.csv, writes README.md
// Build: c++ -std=c++17 -O2 -o gen-readme gen-readme.cpp
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace fs = std::filesystem;

static std::string extract(const std::string& line, const std::string& key) {
    auto pos = line.find(key + "=");
    if (pos == std::string::npos) return {};
    pos += key.size() + 1;
    if (pos < line.size() && line[pos] == '"') {
        auto end = line.find('"', ++pos);
        return end == std::string::npos ? std::string{} : line.substr(pos, end - pos);
    }
    auto end = line.find(' ', pos);
    return line.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
}

static std::string lang_display(const std::string& l) {
    if (l == "cpp")        return "C++";
    if (l == "py" ||
        l == "python3" ||
        l == "python")     return "Python";
    if (l == "java")       return "Java";
    if (l == "ts" ||
        l == "typescript") return "TypeScript";
    if (l == "js" ||
        l == "javascript") return "JavaScript";
    if (l == "go")         return "Go";
    if (l == "rs" ||
        l == "rust")       return "Rust";
    if (l == "kt" ||
        l == "kotlin")     return "Kotlin";
    return l;
}

static std::string diff_badge(const std::string& d) {
    if (d == "Easy")   return "🟢 Easy";
    if (d == "Medium") return "🟡 Medium";
    if (d == "Hard")   return "🔴 Hard";
    return "—";
}

int main(int argc, char* argv[]) {
    fs::path root = argc > 1 ? fs::path(argv[1]) : fs::current_path();

    // Load difficulty cache (id,difficulty per line)
    std::map<int, std::string> diff;
    {
        std::ifstream f(root / "scripts" / "difficulty.csv");
        std::string line;
        while (std::getline(f, line)) {
            auto c = line.find(',');
            if (c != std::string::npos)
                diff[std::stoi(line.substr(0, c))] = line.substr(c + 1);
        }
    }

    // Scan problems/
    struct Problem { int id; std::string slug, lang, site, title, file; };
    std::vector<Problem> problems;

    for (auto& entry : fs::directory_iterator(root / "problems")) {
        if (!entry.is_regular_file()) continue;
        std::ifstream f(entry.path());
        std::string first;
        if (!std::getline(f, first) || first.find("@leetcode") == std::string::npos) continue;
        std::string id_str = extract(first, "id");
        if (id_str.empty()) continue;
        problems.push_back({
            std::stoi(id_str),
            extract(first, "slug"),
            extract(first, "lang"),
            extract(first, "site"),
            extract(first, "title"),
            entry.path().filename().string(),
        });
    }
    std::sort(problems.begin(), problems.end(),
              [](const Problem& a, const Problem& b) { return a.id < b.id; });

    int easy = 0, med = 0, hard = 0;
    for (auto& p : problems) {
        auto it = diff.find(p.id);
        if (it == diff.end()) continue;
        if (it->second == "Easy")   easy++;
        else if (it->second == "Medium") med++;
        else if (it->second == "Hard")   hard++;
    }

    std::ofstream out(root / "README.md");
    out << "# leetcode-problems\n\n"
        << "My LeetCode solutions, managed with "
           "[leetcode-cli](https://github.com/StevenLi-phoenix/leetcode-cli).\n\n"
        << "**" << problems.size() << " solved** — "
        << "🟢 " << easy << " Easy · "
        << "🟡 " << med  << " Medium · "
        << "🔴 " << hard << " Hard\n\n"
        << "| # | Title | Difficulty | Lang |\n"
        << "|---|-------|------------|------|\n";

    for (auto& p : problems) {
        auto it = diff.find(p.id);
        out << "| [" << p.id << "](https://" << p.site << "/problems/" << p.slug << "/) "
            << "| [" << p.title << "](problems/" << p.file << ") "
            << "| " << diff_badge(it != diff.end() ? it->second : "") << " "
            << "| " << lang_display(p.lang) << " |\n";
    }

    std::cout << "Written README.md (" << problems.size() << " problems)\n";
}
