void degravity(int Ratio)
{// �������� ������ ��������������
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void clearL()
{// ��������� ��� ��������� ����������
     clearlocalvar();
}

void dasher( float Vx, float Vy, float Vz )
{// ����������� �� X, Y � Z
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy);
}
