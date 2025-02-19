int candy(vector<int>& ratings) {//better
        int n=ratings.size();
        if(n==1)return 1;
        int ans=0;
        vector<int>sum(ratings.size(),1);//store sum of ratings 
        for(int i=1;i<ratings.size();i++){//left to right check if right neighbour greater then update sum val from 1 to..
           if(ratings[i]>ratings[i-1])sum[i]=sum[i-1]+1;
        }
        int sumx=sum[n-1];
        for(int i=n-2;i>=0;i--){//right to left check if left neighbour greater or not if greater then check sum then update sum
            if(ratings[i]>ratings[i+1]){
                if(sum[i]<=sum[i+1])sum[i]=sum[i+1]+1;
            }
            sumx+=sum[i];//answer 
        }
        return sumx;
    }
//OPTIMAL
int candy(vector<int>& ratings) {//1 2 3 4 == 4 3 2 1 expect peak val only possible different 
        int n=ratings.size();
        int i=1;
        int sum=1;
        while(i<n) {
            if(ratings[i]==ratings[i-1]) {//if plateau or same val then 1
                sum+=1;
                i++;
                continue;
            }
            int peak=1;
            while(i<n && ratings[i]>ratings[i-1]) {//rising slope just add vals 
                peak+=1;
                i++;
                sum+=peak;
            }
            int down=0;
            while(i<n && ratings[i]<ratings[i-1]) {//falling slope just add vals and only val change possible is peak if lowest val >peak 
                down+=1;
                i++;
                sum+=down;
            }
            down++;
            if(down>peak) {
                sum+=down-peak;
            }
        }
        return sum;
    }
