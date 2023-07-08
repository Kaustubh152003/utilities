int is_sub_equal(char[] str1,int offset,char[] str2)
    {
        int j=0;
        while(str1[j+offset]!='\0' && str2[j]!='\0' && str1[offset+j]==str2[j])
        j++;
        if(str2[j]=='\0')
        return 1;
        else
        return 0;
        
    }
    int func(char[] str1,char[] str2)
    {
        int j=0;
        while(str1[j]!='\0' && is_sub_equal(str1,j,str2)!=1)
        j++;
        if(str1[j]=='\0')
        return -1;
        else
        return j;
    }
    void covert_to_charr(String s,char[] str)
    {
        int j=0;
        while(j<s.length())
        {
            str[j]=s.charAt(j);
            j++;
        }
        str[j]='\0';
    }
    int substring_finder(String s, String x)
    {
       char[] str1=new char[s.length()+1];
       char[] str2=new char[x.length()+1];
       covert_to_charr(s,str1);
       covert_to_charr(x,str2);
        return func(str1,str2);
       
    }
