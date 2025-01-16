int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int xorr1 = 0 , xorr2 = 0 ;
    if(nums1Size & 1){
        for(int  i = 0 ; i < nums2Size ; i++){
            xorr2 ^= nums2[i] ;
        }
    }
    if(nums2Size & 1){
        for(int  i = 0 ; i < nums1Size ; i++){
            xorr1 ^= nums1[i] ;
        }
    }
    return xorr1 ^ xorr2 ;
}