package OOP_1;
public class task {
    public static void main(String[] args) {
        osn a = new osn();
        number b = new number(),d = new number();
        b.Init(1,1);
        System.out.println(b.rounding());
        o c = new o();
        b.rounding(c);
        System.out.println(c.a);
        a.Init(1, 1,"fdsfsdf");
        a.Add(1, 1);
        a.Add(4, 4);
        a.Add(3, 3);
        a.Insert(1, 4, 4);
        a.Display();
        a.delete(2);
        a.Display();
        d.Init(5, 5);
        d.Better(d, b).Display(); d.Better(b).Display();
        a = new osn();
        a.Init(1,1,"person duded dad f's safe standford's ");
        String s1 = a.getname(),s2,s3 = s1.substring(0,s1.indexOf(" "));
        s1 = s1.substring(s1.indexOf(" ")+1);
        int k = 0,q  =  5,f =1;
        while(f==1){
            k = s1.indexOf(" ");
            if(!(k>=0)) break;
            s2 = s1.substring(0,k);
            s1 = s1.substring(k+1);
            if(s2.length()>q) s3 = s3+" " +s2;
            else s3 = s2 +" "+s3;
        }
        System.out.printf("%s",s3);
    }

}
class o{
    public double a;
}
class number{
    private double first;
    private double second;

    public void Init(double a,double b){
        first = a;
        second = b;
    }

    public void Display(){
        System.out.println(first +"\t" + second);
    }

    public double GetFirst(){
        return first;
    }

    public double GetSecond(){
        return second;
    }

    public double getD(){
        return first+second;
    }
    public  void  rounding(o k){
        if(second>0.50){
            k.a = first+1;
        }
        else k.a = first;
    }
    public double rounding(){
        double ret = 0;
        if(second>0.50){
            ret = first+1;
        }
        else ret = first;
        return ret;
    }
    public number Better(number a,number b){
        if(a.rounding()>b.rounding()) return a;
        else return  b;
    }
    public number Better(number a){
        if(this.rounding()>a.rounding()) return this;
        else return a;
    }
}
class osn{
    private String name;
    final public int N = 10;
    private number[] a = new number[N];
    private double x,y;
    private int count=0;
    public  void putname(String m){
        name = m;
    }
    public String getname(){
        return name;
    }
    public void Add(double x,double y){
        a[count].Init(x,y);
        count+=1;
    }
    public void Insert(int f, double x,double y){
        if(f<count){
            for(int i = count;i>f;i--) a[i] = a[i-1];
            a[f].Init(x,y);
            count++;
        }
        else Add(x,y);
    }
    public void delete(int f){
        for(int i = f;i<count-1;i++) a[i]=a[i+1];
        count--;
    }
    public void Init(double x1,double y1,String n){
        name = n;
        for (int i = 0;i<N;i++) a[i] = new number();
        x = x1;
        y = y1;
    }
    public void Display(){
        System.out.println(name);
        for (int i =0;i<count;i++) a[i].Display();
        System.out.println(x + "\n" + y);
    }
    public double math(){
        int o = 1;
        for(int i = 0;i<count; i++) o*=a[i].getD();
        return (o*y);
    }
}