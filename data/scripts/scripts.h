void degravity(int Ratio)
{// Изменить эффект антигравитаций
    void self = getlocalvar("self");
    changeentityproperty(self, "antigravity", Ratio);
}

void clearL()
{// Отчистить все локальные переменные
     clearlocalvar();
}

void dasher( float Vx, float Vy, float Vz )
{// Перемещение по X, Y и Z
    void self = getlocalvar("self");
    int dir = getentityproperty(self,"direction");

    if(dir==0){
      Vx = -Vx ;
    }

    changeentityproperty(self, "velocity", Vx, Vz, Vy);
}
