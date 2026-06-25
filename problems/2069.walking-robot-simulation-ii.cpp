// @leetcode id=2069 questionId=2178 slug=walking-robot-simulation-ii lang=cpp site=leetcode.com title="Walking Robot Simulation II"
class Robot {
public:
int W, H;
int pos;
int perim;
vector<pair<int,int>> cells;
vector<string> dirs;
bool moved;
Robot(int width, int height) {
W = width; H = height;
perim = 2*(W-1) + 2*(H-1);
moved = false;
pos = 0;
for(int x=0;x<W;x++) { cells.push_back({x,0}); dirs.push_back("East"); }
for(int y=1;y<H;y++) { cells.push_back({W-1,y}); dirs.push_back("North"); }
for(int x=W-2;x>=0;x--) { cells.push_back({x,H-1}); dirs.push_back("West"); }
for(int y=H-2;y>0;y--) { cells.push_back({0,y}); dirs.push_back("South"); }
dirs[0] = "South";
}
void step(int num) {
moved = true;
pos = (pos + num) % perim;
}
vector<int> getPos() {
return {cells[pos].first, cells[pos].second};
}
string getDir() {
if(!moved) return "East";
return dirs[pos];
}
};
