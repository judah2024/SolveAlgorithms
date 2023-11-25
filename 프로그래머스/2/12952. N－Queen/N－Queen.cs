using System;
using System.Collections.Generic;

public class Solution {
    
    int answer = 0;
    
    public int solution(int n) {
        int[] checks = new int[n];

        for (int i = 0; i < checks.Length; ++i)
        {
            checks[i] = -1;
        }

        tracking(0, n, checks);
        return answer;
    }
    
    void tracking(int pDepth , int pLastDepth, int[] pChecks){
        if (pDepth == pLastDepth) // 타지막 까지 도달한 경우 "Q" 를 전부 배치한 것
        {
            answer++;
            return;
        }

        for (int i = 0 ; i < pLastDepth; ++i)
        {
            if (isCheck(i, pDepth, pChecks)) // 탐색 과정에서 불필요한 경우의 수 제외
            {
                pChecks[pDepth] = i;
                tracking(pDepth + 1, pLastDepth, pChecks);
                pChecks[pDepth] = -1;
            }
        }
    }
    
    bool isCheck(int pN, int pDepth, int[] pChecks) { // 예외 확인
        bool isBool = true;

        for (int i = 0; i < pChecks.Length; ++i)
        {
            if (-1 < pChecks[i])
            {
                if (pChecks[i] == pN)
                {
                    isBool = false;
                    break;
                }
                else if (pChecks[i] + (pDepth - i) == pN)
                {
                    isBool = false;
                    break;
                }
                else if (pChecks[i] - (pDepth - i) == pN)
                {
                    isBool = false;
                    break;
                }
            }
        }

        return isBool;
    }
}