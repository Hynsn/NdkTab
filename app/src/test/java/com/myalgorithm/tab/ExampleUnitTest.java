package com.myalgorithm.tab;

import android.util.Log;

import com.github.promeg.pinyinhelper.Pinyin;

import net.sourceforge.pinyin4j.PinyinHelper;
import net.sourceforge.pinyin4j.format.HanyuPinyinCaseType;
import net.sourceforge.pinyin4j.format.HanyuPinyinOutputFormat;
import net.sourceforge.pinyin4j.format.HanyuPinyinToneType;
import net.sourceforge.pinyin4j.format.exception.BadHanyuPinyinOutputFormatCombination;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;

import static org.junit.Assert.*;

/**
 * Example local unit test, which will execute on the development machine (host).
 *
 * @see <a href="http://d.android.com/tools/testing">Testing documentation</a>
 */
public class ExampleUnitTest {
    @Test
    public void addition_isCorrect() {
        assertEquals(4, 2 + 2);
    }

    @Test
    public void test() {
        String result = "<applications>"
                +"<versions__delta>1</versions__delta>"
                +"<apps__hashcode></apps__hashcode>"
                +"</applications>"+"<applications>"
                +"<versions__delta>1</versions__delta>"
                +"<apps__hashcode></apps__hashcode>"
                +"</applications>"+"<applications>"
                +"<versions__delta>1</versions__delta>"
                +"<apps__hashcode></apps__hashcode>"
                +"</applications>"+"<applications>"
                +"<versions__delta>1</versions__delta>"
                +"<apps__hashcode></apps__hashcode>"
                +"</applications>"+"<applications>"
                +"<versions__delta>1</versions__delta>"
                +"<apps__hashcode></apps__hashcode>"
                +"</applications>";
        byte[] buffer = new byte[500];
        long start = System.currentTimeMillis();
        for (int i = 0; i < 10000; i++) {
             buffer = Arrays.copyOf(result.getBytes(),buffer.length);
        }
        long end = System.currentTimeMillis();
        System.out.println("sss " + buffer.length+","+(end-start));
    }

    @Test
    public void testPermutation(){
        String string = "aaccdd";
        ArrayList<String> list = Permutation(string);
        for(int i=0;i<list.size();i++)
            System.out.println(list.get(i));
    }

    public static ArrayList<String> Permutation(String str)
    {
        ArrayList<String> list = new ArrayList<String>();
        if(str==null || str.length()==0) return list;
        perm(list, str.toCharArray(), 0);

        return list;
    }
    public static void perm(ArrayList<String> list, char[] str, int k){
        //递归基
        if(k==str.length-1){
            String chars = new String(str);
            list.add(chars);
            return;
        }
        for(int i=k; i<str.length;i++){
            if(i==k || (str[i]!=str[k])){
                swap(str, k, i);
                perm(list, str, k+1);
                swap(str,k, i);
            }
        }
    }

    public static void swap(char[] str,int i,int j)
    {
        char temp = str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}