//http://peter.bourgon.org/blog/2008/12/12/boost-thread-kindof-sucks.html
#include <boost/thread/mutex.hpp>
#include <boost/thread/condition.hpp>
/*
class Monitor
{
protected:
    boost::mutex	monitor_mutex;
    boost::condition	monitor_condition;

public:
    Monitor() { }
    virtual ~Monitor() { }

    void wait()
    {
        monitor_condition.wait(monitor_mutex);
    }

    bool timed_wait_ms(int i_duration_ms)
    {
        boost::xtime::xtime_nsec_t total_ns(i_duration_ms * 1000000);
        boost::xtime::xtime_sec_t seconds(total_ns / 1000000000);
        boost::xtime::xtime_nsec_t remainder_ns(total_ns % 1000000000);

        boost::xtime xt;
        boost::xtime_get(&xt, boost::TIME_UTC);
        xt.sec += seconds;
        xt.nsec += remainder_ns;
        return monitor_condition.timed_wait(monitor_mutex, xt);
    }

    void notify_one()
    {
        monitor_condition.notify_one();
    }

    void notify_all()
    {
        monitor_condition.notify_all();
    }

    typedef boost::mutex::scoped_lock Synchronize;

};


class MyWorker : public ThreadBase, public Monitor
{
private:
    bool m_running;
    Resource* m_resource;

public:
    MyWorker(Resource* i_resource) : m_running(false), m_resource(i_resource) { }

    virtual void run()
    {
        Synchronize sync(monitor_mutex);
        m_running = true;
        while (m_running && m_resource != NULL)
        {
            m_resource->more_work(); // presumably Resource is threadsafe
            timed_wait_ms(1000);
        }
    }

    void stop()
    {
        Synchronize sync(monitor_mutex);
        m_running = false;
        notify_all();
    }
};
*/
