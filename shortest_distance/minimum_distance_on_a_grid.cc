#if __cplusplus < 201703
#error "C++17 and higher is required"
#endif

// Introduction ---------------------------------------------------------------
const char introduction[] = "\
/* ************************************************************************** *\n\
 *          MINIMUM DISTANCE ON A GRID FROM SOURCE TO DESTINATION             *\n\
 *                                                                            *\n\
 *  This code gets a grid which contains four types of elements where         *\n\
 *      '*' represents a visitable cell                                       *\n\
 *      '0' represents a unvisitable cell                                     *\n\
 *      's' represents the source cell                                        *\n\
 *      'd' represents the destination cell                                   *\n\
 *                                                                            *\n\
 *  The code uses the BFS(breadth first search) idea for solving the problem  *\n\
 *  For more info. RussellKajouri@gmail.com                                   *\n\
 *                                                                            *\n\
 * ************************************************************************** */\n";

// Headers --------------------------------------------------------------------
#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using vec2dchar = vector < vector < char > >;

// ----------------------------------------------------------------------------
// Every cell is an object of the struct 'Cell', which has a row, column and dist.
// This approach finds the first minimum path and is unable to find other
// paths
struct Cell
{
	int row;
	int col;
	int dist;
	Cell( int r, int c, int d ) : row(r), col(c), dist(d) {}
	Cell( const Cell& cell )
	{
		this -> row = cell.row;
		this -> col = cell.col;
		this -> dist = cell.dist;
	}
};

// operator overloadding to display 2d vector ---------------------------------
template <typename T>
std::ostream& operator<< ( std::ostream& o, const std::vector<std::vector<T>>& v)
{
	for( const std::vector<T>& row : v  )
	{
		for ( const T& elem : row )
			o << elem << ' ';
		o << endl;
	}
	return o;
}

// Show tracker ---------------------------------------------------------------
void show_tracker( vec2dchar grid, const int r, const int c )
{
	grid[r][c] = '%';
	cout << grid << endl;
}

// Minimum distance -----------------------------------------------------------
int minimum_distance( const vec2dchar grid, const int& rows, const int& cols )
{
	Cell source ( 0, 0, 0 );

	// to check the situation of each cell, we need a boolean 2d array
	bool visited [rows] [cols] { false };
	for( int r = 0; r < rows; r++ )
		for( int c = 0; c < cols; c++ )
		{
			if ( grid[r][c] == '0' ) visited[r][c] = true;
			if ( grid[r][c] == 's' )
			{
				source.row = r;
				source.col = c;
				visited[r][c] = true;
			}
		}

	// At this stage, the code knows where the source is and which cells are unvisitable
	
	std::queue < Cell > path;
	path.push( source );

	while ( !path.empty() )
	{
		Cell cell( path.front() );
		show_tracker( grid, path.back().row, path.back().col );
		path.pop();

		// Destination found?
		if ( grid[cell.row][cell.col] == 'd' )
			return cell.dist;

		// moving up
		if ( cell.row - 1 >= 0 && visited[cell.row - 1][cell.col] == false )
		{
			path.push( Cell( cell.row - 1, cell.col, cell.dist + 1 ) );
			visited[cell.row - 1][cell.col] = true;
		}

		// moving down
		if ( cell.row + 1 < rows && visited[cell.row + 1][cell.col] == false )
		{
			path.push( Cell( cell.row + 1, cell.col, cell.dist + 1 ) );
			visited[cell.row + 1][cell.col] = true;
		}

		// moving left
		if ( cell.col - 1 >= 0 && visited[cell.row][cell.col - 1] == false )
		{
			path.push( Cell( cell.row, cell.col - 1, cell.dist + 1 ) );
			visited[cell.row][cell.col - 1] = true;
		}

		// moving right
		if ( cell.col + 1 < cols && visited[cell.row][cell.col + 1] == false )
		{
			path.push( Cell( cell.row, cell.col + 1, cell.dist + 1 ) );
			visited[cell.row][cell.col + 1] = true;
		}
	}

	// means there is no path to reach destination
	return -1;
}

// Main function --------------------------------------------------------------
int main()
{
	cout << introduction << endl;

	const int rows = 4;
	const int cols = 4;

	vec2dchar grid {
		{'0', '*', '0', 's'},
		{'*', '0', '*', '*'},
		{'0', '*', '*', '*'},
		{'d', '*', '*', '*'} };

	cout << "Initial configuration\n\n" << grid << endl;
	cout << "shortest found path: " minimum_distance( grid, rows, cols ) << endl;


}
