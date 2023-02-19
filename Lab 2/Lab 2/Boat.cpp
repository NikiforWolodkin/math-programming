#include "Boat.h"
#include "Combi.h"
namespace boatfnc
{
    bool compv(combi::accomodation s, const int ming[],
        const int maxg[], const int v[])
    {
        int i = 0;
        while (i < s.m && v[s.ntx(i)] <= maxg[i] && v[s.ntx(i)] >= ming[i])i++;
        return (i == s.m);
    };
    int calcc(combi::accomodation s, const int c[])
    {
        int rc = 0;
        for (int i = 0; i < s.m; i++) rc += c[s.ntx(i)];
        return rc;
    };
    void copycomb(short m, short* r1, const short* r2)
    {
        for (int i = 0; i < m; i++)  r1[i] = r2[i];
    };
}
int boat_�(      // ������� ���������� ����� �� ��������� �����������
    short m,      // [in] ���������� ���� ��� �����������
    int minv[],   // [in] ����������� ��� ���������� �� ������  ����� 
    int maxv[],   // [in] ������������ ��� ����������� ������ ����� 
    short n,      // [in] ����� �����������  
    const int v[],// [in] ��� ������� ����������  
    const int c[],// [in] ����� �� ��������� ������� ����������   
    short r[]     // [out] ������ ��������� �����������  
)
{
    combi::accomodation s(n, m);
    int rc = 0, i = s.getfirst(), cc = 0;
    while (i > 0)
    {

        if (boatfnc::compv(s, minv, maxv, v))


            if ((cc = boatfnc::calcc(s, c)) > rc)
            {
                rc = cc; boatfnc::copycomb(m, r, s.sset);
            }

        i = s.getnext();
    };
    return rc;
}


