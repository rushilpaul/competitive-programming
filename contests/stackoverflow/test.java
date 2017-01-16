import java.nio.*;
class test
{
	public static void main(String args[])
	{
		byte[] bytes = ByteBuffer.allocate(4).putInt(100).array();
		for(int a=0;a<bytes.length;a++) System.out.print(bytes[a] + " ");
		System.out.println();
	}
}
