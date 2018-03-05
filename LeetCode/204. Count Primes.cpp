class Solution {
public:

    int countPrimes(int n)
    {
        //对应的标记
        vector <bool> prime_mark;

        for (int i = 0; i < n; i++)
        {
            // 0，1 都不是素数
            if (i<2)
                prime_mark.push_back(false);
            
            //初始余下所有小于的数都是素数
            
            else
                prime_mark.push_back(true);
        }
        
        //计算素数的数目
        int cnt = 0;

        for (int j = 2; j < sqrt(n); j++)
        {
            //如果当前是素数
            if (prime_mark[j] == true)
            {
                //将当前素数的倍数的数都标记为合数
                for (int k = j * 2; k < n; k = j + k)
                {
                    prime_mark[k] = false;
                }

            }
        }

        for (int j = 2; j < n; j++)
        {
            if (prime_mark[j] == true)
            {
               //愿意的话可以输出当前素数
               //加一句cout<<j<<" ";
                cnt++;
            }
                
        }
        return cnt;
    }
};
