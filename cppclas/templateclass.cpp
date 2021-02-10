template<class t>

class complex_number
{
private:
    t real, img;
public:
    complex_number(t real, t img);
    complex_number();
    complex_number<t> add(complex_number<t>& a, complex_number<t>& b);
    complex_number<t> sub(complex_number<t>& a, complex_number<t>& b);
    ~complex_number();
};

template<class t>
complex_number<t>::complex_number()
{
    real = 0;
    img = 0;
}

template<class t>
complex_number<t>::complex_number(t real, t img)
{
    this->img = img;
    this->real = real;
}

template<class t>
complex_number<t> add(complex_number<t>& a, complex_number<t>& b)
{
    complex_number<t> sum(a.real+b.real, a.img+b.img);
    return sum;
}

template<class t>
complex_number<t> sub(complex_number<t>& a, complex_number<t>& b)
{
    complex_number<t> diff(a.real-b.real, a.img-b.img);
    return diff;
}

template<class t>
complex_number<t>::~complex_number()
{
}

int main()
{
    return 0;
}


