#ifndef MYBILL_H
#define MYBILL_H


class myBill
{
    public:
        myBill();
        virtual ~myBill();
        myBill(const myBill& other);
        myBill& operator=(const myBill& other);

        unsigned int Getm_Counter() { return m_Counter; }
        void Setm_Counter(unsigned int val) { m_Counter = val; }

    protected:

    private:
        unsigned int m_Counter;
};

#endif // MYBILL_H
