//change antigravity effect
void degravity(int Ratio)
{
     void self = getlocalvar("self");
     changeentityproperty(self, "antigravity", Ratio);
}
//clear local variables
void clearL()
{
     clearlocalvar();
}

//move xyz
void dasher(float Vx, float Vy, float Vz)
{
     void self = getlocalvar("self");
     int dir = getentityproperty(self, "direction");

     if(dir == 0)
     {
          Vx = -Vx;
     }

     changeentityproperty(self, "velocity", Vx, Vz, Vy);
}