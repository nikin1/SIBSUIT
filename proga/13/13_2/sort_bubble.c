void bubble( int size, int *a, int *cnt_C, int *cnt_M) {
    *cnt_C = 0;
    *cnt_M = 0;
    for( int i = 0; i < size - 1; i++ ) {
        for ( int j = (size - 1); j > i; j-- ) {
            if( a[j-1] > a[j] ) {
                *cnt_C = *cnt_C + 1;
                *cnt_M = *cnt_M + 3;
                int k = a[j-1];
                a[j-1] = a[j];
                a[j] = k;
            }
        }
    }
}
