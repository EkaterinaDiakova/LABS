#ifndef DYNAMIC_ARRAY_H_
#define DYNAMIC_ARRAY_H_

#include<iostream>

using namespace std;

template <typename T>
class dynamic_array
{
 private:
    int m_size; //������ ������� (���������� ��������� � �������, ��������� ������������)
    int m_capacity; //"�����������" ������� (���������� ������)
    T * m_data; //��������� �� ������� ������, ��� �������� ���� �������� �������

 public:
    dynamic_array() //����������� �� ���������
    {
        m_size = 0;
        m_capacity = 0;
        m_data = NULL;
    }

    dynamic_array(const dynamic_array<T> & a) //����������� �����������
    {
        m_size = a.m_size;
        m_capacity = m_size;
        m_data = NULL;
        if (m_size != 0)
            m_data = new T[m_size];
        else
            m_data = 0;
        for (int i = 0; i < m_size; ++i)
        {
            m_data[i] = a.m_data[i];
        }
    }

    dynamic_array(int size) //�����������, ������� ������� ������ ��������� �������
    {
        m_size = size;
        m_capacity = size;
        if (size != 0)
            m_data = new T[size];
        else
            m_data = 0;
    }

    dynamic_array(T* items, int count) //����������� ��������� �� ��������� �������
    {
    	m_data = new T[count];
    	m_capacity = count;
    	m_size = count;
    	for (int i = 0; i < m_size; ++i)
    	{
    		m_data[i] = items[i];
    	}
    }

    ~dynamic_array() //����������
    {
        if (m_data)
            delete[] m_data;
    }

    void resize(int size) //��������� ������� �������
    {
        if (size > m_capacity)
        {
            int new_capacity = size;
            T * new_data = new T[new_capacity];
            for (int i = 0; i < m_size; ++i)
            {
                new_data[i] = m_data[i];
            }
            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
        m_size = size;
    }

    int get_size() const //�������� ������ �������
    {
        return m_size;
    }

    void set(int i, T value)
    {
    	if((i >= m_size) || (i < 0)) throw -1;// ����������
    	m_data[i] = value;
    }

    T & operator[] (int i)
    {
    	if((i >= m_size) || (i < 0)) throw -1;// ����������
        return m_data[i];
    }
};

template<typename T>
ostream & operator << (ostream & out, dynamic_array<T> a)
{
    for (int i = 0; i < (a.get_size()); ++i)
    {
        out << a[i] << " ";
    }
    return out;
}




#endif /* DYNAMIC_ARRAY_H_ */
