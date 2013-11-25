#ifndef GRID_H
#define GRID_H

template<class T>
class Grid
{
	public:
		Grid() : height(0), width(0), cells(0)
		{}

		Grid(int height_, int width_) : height(height_), width(width_), cells(height_*width_)
		{}

		Grid(int height_, int width_, T initial) : height(height_), width(width_), cells(height_*width_, initial)
		{}

		~Grid()
		{}

		int getHeight() const
		{
			return(height);
		}

		int getWidth() const
		{
			return(width);
		}

		// Element access.
		T &operator()(int y, int x)
		{
			return(cells.at(y*width+x));
		}

		T operator()(int y, int x) const
		{
			return(cells.at(y*width+x));
		}

	private:
		int height, width;                 // The dimensions of the grid.
		std::vector<T> cells;              // The grid cells.
};

#endif // GRID_H
