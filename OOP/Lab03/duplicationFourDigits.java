public class duplicationFourDigits
{
    public static void main(String[] args) {
        int nums[] = {1,2,3,4};
        int number[] = new int[4];
        for(int i=0;i<4;i++)
        {
            number[0] = nums[i];
            
                for(int j = 0; j<4;j++)
                {
                    number[1] = nums[j];
                    for(int k = 0; k<4;k++)
                    {
                        number[2] = nums[k];
                        for(int l=0;l<4;l++)
                        {
                            number[3] = nums[l];
                            for(int m : number)
                            {
                                System.out.print(m);
                            }
                            System.out.println("");
                        }
                    }
                }
                }
            
        }
    }
