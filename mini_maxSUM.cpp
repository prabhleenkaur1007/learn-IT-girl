////Given five positive integers in an array, find the minimum and maximum values that can be calculated by summing exactly four of the five integers.//
/////// Then print the respective minimum and maximum values as a single line of two space-separated long integers./////
//////////code for the function////////////////
void miniMaxSum(vector<int> arr) {
        ///////////declaring int///////////
        long int a,b,c,d,e,max,min, maxSum{0}, minSum{0};
        a=arr[0];
        b=arr[1];
        c=arr[2];
        d=arr[3];
        e=arr[4];
        //////////////////max////////////
        int max1=fmax(a,b);
        int max2=fmax(c,d);
        int max3=fmax(max1,max2);
        int max4=fmax(e,max3);
        max=max4;
        
        //////////////////min /////////////
        int min1=fmin(a,b);
        int min2=fmin(c,d);
        int min3=fmin(min1,min2);
        int min4=fmin(e,min3);
        min=min4;
        ///////////////max sum ////////////
        for(int i{0}; i<5; i++){
                 maxSum+=arr[i];
        }
        maxSum-=min;
        ///////////min sum//////////
        for(int i{0}; i<5; i++){
                  minSum+=arr[i];
        }
        minSum-=max;
        
        cout<<minSum<<" "<<maxSum;
}

