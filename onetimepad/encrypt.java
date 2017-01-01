import java.util.Random;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class encrypt{
	public static void main(String[] args)throws FileNotFoundException{
		Random rg;
		String test="Hello_World!**";
		String encry="", decry="", mid="";
		long xor=0, temp=0, seed=0;
		if(args.length>0)seed=Long.parseLong(args[0]);
		if(args.length>1){
			test="";
			for(int i=1; i<args.length; i++)
				test+=args[i]+" ";
		}
		if(seed==0)rg=new Random();
		else rg=new Random(seed);
		for(int i=0; i<test.length(); i++){
			xor=rg.nextInt();
			if(xor<0)xor=xor/-1;
			temp=test.charAt(i)^xor;
			encry+=temp+" ";
		}
		System.out.println(encry+"\n");
		PrintWriter msg = new PrintWriter("MSG.txt");
		msg.println(encry);
		msg.close();
	}
}