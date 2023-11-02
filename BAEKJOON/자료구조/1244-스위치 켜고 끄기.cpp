//남학생은 스위치 번호가 자기가 받은 수의 배수이면, 그 스위치의 상태를 바꾼다. 
//여학생은 자기가 받은 수와 같은 번호가 붙은 스위치를 중심으로 좌우가 대칭, 가장 많은 스위치를 포함하는 구간을 찾아서,
//그 구간에 속한 스위치의 상태를 모두 바꾼다. 이때 구간에 속한 스위치 개수는 항상 홀수

#include <iostream>
using namespace std;

int gen, num;
int cnt, stu;
int number;
unsigned int arr[102] = {0, };

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> cnt;
    for (int i=1; i <= cnt; i++)
    {
        cin >> arr[i];
    }
    cin >> stu;
    for (int i=0; i<stu; i++)
    {
        cin >> gen >> num;
        if (gen == 1)
        {
            for (int i=1; i <= cnt; i++)
            {
                if (i % num == 0)
                {
                    if (arr[i])
                        arr[i] = 0;
                    else
                        arr[i] = 1;
                }
            }            
        }
        else
        {

            int j = 0;
            number = num;
            for (int i=1; i <= cnt; i++)
            {
                if (arr[number - j] == arr[number + j] && (number - j) > 0 && (number + j) <= cnt )
                {
                    if (arr[number - j])
                    {
                        arr[number - j] = 0;
                        arr[number + j] = 0;
                    }
                    else
                    {
                        arr[number - j] = 1;
                        arr[number + j] = 1;
                    }
                    j++;
                }
                else
                    break ;
            }
        }
    }
    for (int i=1; i<= cnt; i++)
    {
        
        cout << arr[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }
}