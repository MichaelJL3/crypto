import java.util.Random;
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class decrypt{
	public static void main(String[] args)throws FileNotFoundException{
		Random reg;
		String encry="", decry="", mid="";
		long xor=0, temp=0, seed=0;

		if(args.length>0)seed=Long.parseLong(args[0]);
		if(seed==0)reg=new Random();
		else reg=new Random(seed);

		File file = new File("MSG.txt");
		Scanner read = new Scanner(file);
		while(read.hasNext())encry+=read.nextLine();
		
		for(int i=0; i<encry.length();){
			xor=reg.nextInt();
			if(xor<0)xor=xor/-1;
			mid=encry.substring(i);
			temp=Long.parseLong(mid.substring(0, mid.indexOf(" ")))^xor;
			decry+=(char)temp+"";
			i+=encry.substring(0, mid.indexOf(" ")).length();
			i++;
		}
		System.out.println(decry);
	}
}