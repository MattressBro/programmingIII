import java.util.concurrent.locks.*;
public class portfolio {
    private static final Lock lock = new ReentrantLock();
    private static int num = 0;
    public static void main(String[] args) {
        Thread t1 = new Thread(() -> countUp());
        Thread t2 = new Thread(() -> countDown());

        System.out.println("Thread 1");
        t1.start();
        try {
            t1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\nThread 2");
        t2.start();
        try {
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    private static void countUp() {
        while (num <= 20) {
            lock.lock();
            try {
                System.out.println(num);
                Thread.sleep(100);
                if (num == 20) break;
                num++;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }
    private static void countDown() {
        while (num >= 0) {
            lock.lock();
            try {
                System.out.println(num);
                Thread.sleep(100);
                num--;
            } catch (InterruptedException e) {
                e.printStackTrace();
            } finally {
                lock.unlock();
            }
        }
    }
}