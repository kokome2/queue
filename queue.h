#include<queue>
#include<algorithm>
#include<mutex>
namespace kmj
{
    template<typename T>
    class stl_wrapping_queue
    {
        public:

            stl_wrapping_queue();
            virtual ~stl_wrapping_queue();

            stl_wrapping_queue(const stl_wrapping_queue& other);
            stl_wrapping_queue(stl_wrapping_queue&& other);

            stl_wrapping_queue& operator=(const stl_wrapping_queue& other) = delete;
            stl_wrapping_queue& operator=(stl_wrapping_queue&& other) = delete;

            bool empty() const;
            T size();
            void enqueue(const T &value);
            void dequeue();
            T front();
            T back();

        protected:
        private:
            std::queue<T> mQueue;
            size_t mLength;
            mutable std::mutex mMutex;

    };

    template<typename T>
    stl_wrapping_queue<T>::stl_wrapping_queue() : mLength(0)
    {
        
    }

    template<typename T>
    stl_wrapping_queue<T>::~stl_wrapping_queue()
    {

    }

    template<typename T>
    stl_wrapping_queue<T>::stl_wrapping_queue(const stl_wrapping_queue& other) : mLength(other.mLength)
    {
        std::unique_lock<std::mutex> lock(mMutex);
            std::copy(other.mQueue, other.mQueue + mLength, mQueue);
    }

    template<typename T>
    stl_wrapping_queue<T>::stl_wrapping_queue(stl_wrapping_queue &&other)
    {
        std::unique_lock<std::mutex> lock(mMutex);
        std::move(other);
    }

    template <typename T>
    inline bool stl_wrapping_queue<T>::empty() const
    {
        std::unique_lock<std::mutex> lock(mMutex);
        return mQueue.empty();
    }

    template <typename T>
    T stl_wrapping_queue<T>::size()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        return mQueue.size();
    }

    template <typename T>
    void stl_wrapping_queue<T>::enqueue(const T &value)
    {
        std::unique_lock<std::mutex> lock(mMutex);
    }

    template <typename T>
    void stl_wrapping_queue<T>::dequeue()
    {
        std::unique_lock<std::mutex> lock(mMutex);

    }

    template <typename T>
    T stl_wrapping_queue<T>::front()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        return mQueue.front();
    }

    template <typename T>
    T stl_wrapping_queue<T>::back()
    {
        std::unique_lock<std::mutex> lock(mMutex);
        return mQueue.back();
    }
}
