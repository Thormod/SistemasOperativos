// Variables de entorno de java

public class variablesJava{
	public static void main(String []args){
		java.util.Properties p = System.getProperties();
		java.util.Enumeration keys = p.keys();
		while(keys.hasMoreElements()){
			System.out.println(keys.nextElement());
		}
	}
}