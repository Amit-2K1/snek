#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell( const Location& loc,Color c );
	int GetGridWidth() const;
	int GetGridHeight() const;
	int GetContent(const Location& loc) const;
	void ConsumeContent(const Location& loc);
	void SpawnContent(std::mt19937 rng, const class Snake& snk, int contentType);
	bool IsInsideBoard( const Location& loc ) const;
	void DrawContents();
	void DrawBorder();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr Color obstacleColor = Colors::Gray;
	static constexpr Color foodColor = Colors::Red;
	static constexpr Color poisonColor = { 64,8,64 };
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	//0 -> empty 1 -> obstacle 2 -> food 3 -> poison
	int hasContents[width * height] = { 0 };
	Graphics& gfx;
};