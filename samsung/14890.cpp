#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
 
int map[100][100];
vector<int> vecArr[200];
 
int main(){
    
    int ans = 0;
    int N, L;
    cin >> N >> L;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>map[i][j];
        }
    }
  
    //벡터 배열에 가로 N개, 세로 N개 넣음.
    for(int row=0; row<N; row++){
        for(int col = 0; col<N; col++){
            vecArr[row].push_back(map[row][col]);
        }
    }
    for(int col=0; col<N; col++){
        for(int row=0; row<N; row++){
            vecArr[col+N].push_back(map[row][col]);
        }
    }
    
    
    
    
 
    for(int i = 0; i<2*N; i++){
        
        bool stop = false;
        int sameHeight = 1;     //기존에 높이 같은 길 얼마나 연속됐는지
        for(int j = 0; j<vecArr[i].size()-1; j++){
            
            if(vecArr[i][j] == vecArr[i][j+1]){ //높이 같은 길 연속되면
                sameHeight++;
                continue;
            }
            
            else if(vecArr[i][j] == vecArr[i][j+1] + 1 ){       //더 낮은 곳을 만났을 때
                
                int cnt = 1;
                bool chk=true;
                for(int k=1; k<L; k++){
                    if(vecArr[i][j+k] == vecArr[i][j+k+1]){	//앞으로 검사할 길에 평평한 길이가 L 만큼 되는지 카운트 
                        cnt++;
                    }
                    else{		//L만큼 다 검사하기도 전에 높이 다른게 있어버리면 
                        chk = false;        //다음 줄로1
                        break;
                    }
 
                }
                if(chk == false){       //다음 줄로2
                    stop = true;		//그 길은 검사 멈춤
                    break;
                }
                else{
                    if(cnt==L){			//연속된 길 L만큼 있어서 경사로 놓을 수 있으면
                        j += cnt-1;
                        sameHeight = 0;		//1로 초기화하면 예제 4에서 에러 발생 
                    }
                }
            }
            
            
            else if(vecArr[i][j] + 1 == vecArr[i][j+1]){       //더 높은 곳을 만났을 때
                
                if(sameHeight>=L) {	//기존에 평평한 길이가 L보다 긴지 체크 
                    sameHeight = 1;
                    continue;
                }
                else{
                    stop = true;	//경사로 못 놓으면 그 길은 탐색 멈춤
                    break;
                }
 
            }
            else if (abs(vecArr[i][j] - vecArr[i][j+1]) >= 2){   //높이 차 1 넘을때     -> 이 부분 else 로 하면 틀림
                stop = true;
                break;
                
            }
        }
        
        if(!stop){
            ans++;
           // cout << i << "\n";
        }
 
    }
    
 
    cout << ans;
    
    
    return 0;
}