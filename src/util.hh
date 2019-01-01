#ifndef EXPLAIN_UTIL_HH
#define EXPLAIN_UTIL_HH

#include <memory>

template<typename D, typename B>
std::unique_ptr<D>
downcast(std::unique_ptr<B>&& p)
{
    auto d = static_cast<D *>(p.release());
    return std::unique_ptr<D>(d);
}

template<typename D, typename B, typename Del>
std::unique_ptr<D, Del>
static_downcast(std::unique_ptr<B, Del>&& p)
{
    auto d = static_cast<D *>(p.release());
    return std::unique_ptr<D, Del>(d, std::move(p.get_deleter()));
}

template<typename D, typename B, typename Del>
std::unique_ptr<D, Del>
dynamic_downcast(std::unique_ptr<B, Del>&& p)
{
    if (D *d = dynamic_cast<D *>(p.get()))
    {
        p.release();

        return std::unique_ptr<D, Del>(d, std::move(p.get_deleter()));
    }

    return std::unique_ptr<D, Del>(nullptr, std::move(p.get_deleter()));
}

#endif //EXPLAIN_UTIL_HH
