#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for(int i=0; i<triangle.size()-1; ++i){
        for(int j=0; j<triangle[i+1].size(); ++j){
            if(j==0)
                triangle[i+1][j] += triangle[i][j];
            else if(j==triangle[i+1].size()-1)
                triangle[i+1][j] += triangle[i][j-1];
            else
                triangle[i+1][j] += max(triangle[i][j-1], triangle[i][j]);
            answer = max(answer, triangle[i+1][j]);
        }
    }

    return answer;
}
