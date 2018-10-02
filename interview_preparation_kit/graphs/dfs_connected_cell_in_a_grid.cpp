#include <bits/stdc++.h>

using namespace std;

#define empty_pair make_pair(-1,-1)

pair<int,int> get_index  ( vector<vector<int> > grid ) {
    for ( int i=0 ; i<grid.size() ; i++ )
        for ( int j =0 ; j<grid[i].size() ; j++ )
            if ( grid[i][j] == 1 )
                return make_pair ( i , j );
    return empty_pair ;
}

int start_count ( pair<int,int> index , vector<vector<int> > &grid , int count ){
    int x = index.first , y = index.second ;
  //  if ( x < 0 or y < 0 or x >=grid.size() or y>=grid[grid.size()-1].size() )  return 0;
    grid[x][y] = 0 ;
    count += 1;
    
    int rows = grid.size() , cols  ; 
    rows > 0 ? cols = grid[rows-1].size() : cols = 0 ;
    
    bool x_neg , y_neg , x_pos , y_pos ;
    x-1 >=0 ? x_neg = true : x_neg = false ;
    y-1 >=0 ? y_neg = true : y_neg = false ;
    x+1 < rows ? x_pos = true : x_pos = false ;
    y+1 < cols ? y_pos = true : y_pos = false ;
    
    if ( x_neg and grid[x-1][y] == 1 )    count+= start_count ( make_pair ( x-1 , y) , grid , 0 );
    if ( x_pos and grid[x+1][y] == 1 )    count+= start_count ( make_pair ( x+1 , y) , grid , 0 );
    if ( y_neg and grid[x][y-1] == 1 )    count+= start_count ( make_pair ( x , y-1) , grid , 0 );
    if ( y_pos and grid[x][y+1] == 1 )    count+= start_count ( make_pair ( x , y+1) , grid , 0 );
    if ( x_neg and y_neg and grid[x-1][y-1] == 1 )  count+= start_count ( make_pair ( x-1 , y-1) , grid , 0 );
    if ( x_neg and y_pos and grid[x-1][y+1] == 1 )  count+= start_count ( make_pair ( x-1 , y+1) , grid , 0 );
    if ( x_pos and y_neg and grid[x+1][y-1] == 1 )  count+= start_count ( make_pair ( x+1 , y-1) , grid , 0 );
    if ( x_pos and y_pos and grid[x+1][y+1] == 1 )  count+= start_count ( make_pair ( x+1 , y+1) , grid , 0 );

    return count ;
}

// Complete the maxRegion function below.
int maxRegion(int rows , int cols , vector<vector<int>> grid) {
    pair<int,int> index ; 
    int max_count = 0 ;
    while ( index = get_index ( grid ) , index != empty_pair ) {
        int current_count = start_count ( index , grid , 0 ) ;
        if ( current_count > max_count )    max_count = current_count ;
    }
    return max_count ;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(n,m,grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
