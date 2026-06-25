CXX      ?= c++
CXXFLAGS := -std=c++17 -O2 -Wall

.PHONY: build update-cache

build: scripts/gen-readme

scripts/gen-readme: scripts/gen-readme.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

# Fetch latest difficulty data from LeetCode, embed in gen-readme.cpp, recompile
update-cache:
	python3 scripts/update-cache.py
	./scripts/gen-readme
	git add scripts/gen-readme.cpp README.md
