vector<int> majorityElementII(vector<int> &arr) {
    int cand1=-1,cand2=-1,votes1=0,votes2=0,freq1=0,freq2=0,n=arr.size();
    for (int i:arr) {
        if (cand1==i) votes1++;
        else if (cand2==i) votes2++;
        else if (votes1==0) {
            cand1=i;
            votes1++;
        }
        else if (votes2==0) {
            cand2=i;
            votes2++;
        }
        else {
            votes1--;
            votes2--;
        }
    }
    for (int i:arr) {
        if (cand1==i) freq1++;
        else if (cand2==i) freq2++;
    }
    if (freq1>n/3&&freq2>n/3) return {cand1,cand2};
    else if (freq1>n/3) return {cand1};
    else if (freq2>n/3) return {cand2};
    return {};
}
