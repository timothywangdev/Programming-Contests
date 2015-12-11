void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            // length of the current layer
            int L=n-2*i;
            // We don't want to move the last element, otherwsie we are
            // swaping an element which has already been swapped(same row or same column)
            for(int offset=0;offset<L-1;offset++){
                int tmp=matrix[i][i+offset];
                matrix[i][i+offset]=matrix[i+L-1-offset][i];
                matrix[i+L-1-offset][i]=matrix[i+L-1][i+L-1-offset];
                matrix[i+L-1][i+L-1-offset]=matrix[i+offset][i+L-1];
                matrix[i+offset][i+L-1]=tmp;
            }
        }
}
