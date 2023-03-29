class Badiya extends Thread{
    public void run()
    {
        try{
            Thread.sleep(4000);
            System.out.println("Thread no. 1");
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupt ho gaya");
        }
    }
}

class Kyabaathai extends Thread{
    public void run()
    {
        try{
            Thread.sleep(3000);
            System.out.println("Thread no. 2");
        }
        catch(InterruptedException e)
        {
            System.out.println("Interrupt ho gaya");
        }
    }
}
class Multithreading{
    public static void main(String args[])
    {
        Badiya B1 =  new Badiya();
        B1.run();
        Kyabaathai K1 = new Kyabaathai();
        K1.run();
    }
}
