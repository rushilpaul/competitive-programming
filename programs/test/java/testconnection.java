import javax.swing.*;
import java.awt.event.*;
import java.net.*;
import java.awt.*;
class testconnection extends Thread implements ActionListener
{
	static JButton test; static int count;
	static testconnection instance; static JFrame f;

	public void init()
	{
		count=0;
		f = new JFrame("Internet test");
		JPanel p = new JPanel();
		test = new JButton("Test Network");
		test.addActionListener(this); test.setActionCommand("test");
		p.add(test);
		f.add(p);
		f.resize(new Dimension(250,80));
		f.setLocation(400,300);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setVisible(true);
	}

	public testconnection()
	{ count = 0; }

	public void actionPerformed(ActionEvent e)
	{
		if(instance.isAlive())
		{
			new JOptionPane().showMessageDialog(f,"Please wait...","Wait",JOptionPane.QUESTION_MESSAGE);
			return;
		}
		if(count == 1) instance = new testconnection();
		String com = e.getActionCommand();
		if(com.equals("test"))
			instance.start();
	}

	public void run()
	{
		count=1;
		new JOptionPane().showMessageDialog(f, "Checking please wait...","Check",JOptionPane.INFORMATION_MESSAGE);
		Socket soc = null;
		try { soc = new Socket("www.google.com",80); JOptionPane.showMessageDialog(f,"Connected to the internet!","Success",JOptionPane.INFORMATION_MESSAGE); soc.close(); }
		catch(Exception er) { JOptionPane.showMessageDialog(f,"Oops! Not connected.\n" + er.getMessage(),"Error", JOptionPane.ERROR_MESSAGE); }
	}


	public static void main(String args[])
	{
		instance = new testconnection();
		instance.init();
	}
}
