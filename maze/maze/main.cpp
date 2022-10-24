//
//  main.cpp
//  maze
//
//  Created by Giovanni Junseo Kim on 2022/09/28.
//

#include <iostream>
#include "Location2D.h"
#include <stack>
using namespace std;

const    int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '0', '1', '0', '0', '0'},
    {'1', '0', '0', '0', '1', '0'},
    {'1', '0', '1', '0', '1', '0'},
    {'1', '0', '1', '0', '1', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};

bool isValidLoc( int r, int c )
{
    if( r < 0 || c < 0 || r>=MAZE_SIZE || c>=MAZE_SIZE ) return false;
    else return map[r][c] == '0' || map[r][c] == 'x' ;
}

int main()
{
    stack<Location2D> locStack;
    stack<Location2D> shortcutStack;
    Location2D entry(1,0);
    map[1][0] = 'S';
    locStack.push( entry );

    while ( locStack.empty() == false ) {
        Location2D  here = locStack.top();
        locStack.pop();
        
        int r = here.row;
        int c = here.col;
        printf( "(%d,%d) ", r, c );
        if( r == 4 && c == 5) {
            printf("미로 탈출 성공, 최단 경로는 다음과 같습니다.\n");
            while(map[r][c] != 'S'){
                shortcutStack.push(Location2D(r,c));
                if(map[r][c] == 'B'){ // 현재 위치는 밑에서 왔다.
                    r = r+1;
                }
                else if(map[r][c] == 'T'){ // 현재 위치는 위에서 왔다.
                    r = r-1;
                }
                else if(map[r][c] == 'R'){ // 현재 위치는 오른쪽에서 왔다.
                    c = c+1;
                }
                else if(map[r][c] == 'L'){ // 현재 위치는 왼쪽에서 왔다.
                    c = c-1;
                }
                else{
                    printf("최단 거리 계산 중 오류 발생.\n");
                    break;
                }
            }
            shortcutStack.push(Location2D(1,0));
            while (!shortcutStack.empty()) {
                Location2D  here2 = shortcutStack.top();
                shortcutStack.pop();
                r = here2.row;
                c = here2.col;
                printf( "(%d,%d) ", r, c );
            }
            printf("\n");
        
            return 0;
        }
        else {
            //map[r][c] = '.';
            if( isValidLoc( r-1, c ) ) { // 위로 갈 수 있다.
                map[r-1][c] = 'B';
                locStack.push(Location2D(r-1,c));
            }
            if( isValidLoc( r+1, c ) ) { // 아래로 갈 수 있다.
                map[r+1][c] = 'T';
                locStack.push(Location2D(r+1,c));
            }
            if( isValidLoc( r, c-1 ) ){ // 왼쪽으로 갈 수 있다.
                map[r][c-1] = 'R';
                locStack.push(Location2D(r,c-1));
            }
            if( isValidLoc( r, c+1 ) ){ // 오른쪽으로 갈 수 있다.
                map[r][c+1] = 'L';
                locStack.push(Location2D(r,c+1));
            }
        }
    }
    printf("미로 탈출 실패\n");
    return 0;
}
