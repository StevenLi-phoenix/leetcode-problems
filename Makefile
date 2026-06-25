CXX      ?= c++
CXXFLAGS := -std=c++17 -O2 -Wall

.PHONY: build update-cache

build: scripts/gen-readme

scripts/gen-readme: scripts/gen-readme.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

update-cache: scripts/gen-readme
	python3 scripts/update-cache.py
	./scripts/gen-readme
	git add scripts/difficulty.csv README.md
