class multiply_matrix
{
    public static void main(String[] args)
    {
        int M1[][] = {{1,2,3,4,5},{6,7,8,9,0}};
        int M2[][] = {{1,2,3},{4,5,6},{7,8,9},{0,1,2},{3,4,5}};
        int M3[][] = new int[2][3];
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                for(int k = 0;k<5;k++)
                {
                    M3[i][j]+=M1[i][k]+M2[k][j];
                }
            }
        }
        
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<3;j++)
            {
                System.out.print(M3[i][j]+" ");
            }
            System.out.println();
        }
    }
}