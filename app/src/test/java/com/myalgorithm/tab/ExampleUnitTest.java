package com.myalgorithm.tab;

import android.util.Log;

import org.junit.Test;

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
}