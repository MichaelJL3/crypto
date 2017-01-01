import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
import javax.swing.JFrame;
import java.awt.Color;
import java.awt.Graphics;
import javax.swing.JPanel;

public class freq extends JPanel{
	static int[][] count= new int[50][50];
	public static void main(String[] args)throws FileNotFoundException{
		JFrame frame = new JFrame("-ANALYZER-");
		String[] msg= new String[105];
		int i=0;
		int height=450, width=400;
		File file = new File("MSG.txt");
		Scanner read = new Scanner(file);
		while(read.hasNext()){
			msg[i]=read.next();
			i++;		
		}
		for(i=0; i<msg.length; i++){
			for(int j=msg.length-1; j>i; j--){
				if(msg[i]!=null&&msg[j]!=null&&msg[i].equals(msg[j])){
					count[j][i]+=1;
				}
			}
		}
		freq analyze = new freq();
        frame.add(analyze);
        frame.setSize(width, height);
        frame.setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        frame.setVisible(true);
	}
	public void paint(Graphics g){
		for(int i=0; i<=20; i++){
            g.drawLine(20*i, 0, 20*i, 400);
            g.drawLine(0, 20*i, 400, 20*i);
        }
	}
}