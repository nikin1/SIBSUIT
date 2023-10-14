void bubble( int size, int *a) {
    
    for( int i = 0; i < size - 1; i++ ) {
        for ( int j = (size - 1); j > i; j-- ) {
            if( a[j-1] > a[j] ) {
                int k = a[j-1];
                a[j-1] = a[j];
                a[j] = k;
            }
        }
    }
}