public class noDuplicationFourDigits {
        public static void main(String[] args) {
            int nums[] = {1,2,3,4};
            int number[] = new int[4];
            int c1=0,c2=0,c3=0,c4=0;
            for(int i=0;i<4;i++)
            {
                number[0] = nums[i];
                c1++;
                    digit2:for(int j = 0; j<4;j++)
                    {
                        number[1] = nums[j];
                        if(repeat(number,nums[j],2)){
                            continue digit2;
                        }
                        c2++;
                        digit3:for(int k = 0; k<4;k++)
                        {
                            number[2] = nums[k];
                            if(repeat(number,nums[k],3)){
                            continue digit3;
                            }
                            c3++;
                            digit4:for(int l=0;l<4;l++)
                            {
                                number[3] = nums[l];
                                if(repeat(number,nums[l],4)){
                                continue digit4;
                                }
                                c4++;
                                for(int m : number)
                                {
                                    System.out.print(m);
                                }
                                System.out.println("");
                                
                                
                            }
                        }
                    }
                    }
                    //System.out.println("C1: " + c1 + "\tC2: " + c2 + "\tC3: " + c3 + "\tC4: " + c4);
                
            }
            static boolean repeat(int a[],int b, int c)
            {
                for(int i = 0; i<c-1;i++)
                {
                    
                        if(a[i] == b)
                        {
                            return true;
                        }
                    
                }
                return false;
            }
    }

