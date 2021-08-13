String temp="";

String s = "kkkkkkkkkkkkkkkkkkkkkkkkkkkk";
  
  int matrix[][5] = 
      {
        {1,1,0,0,1},
        {1,1,1,0,0},
        {0,0,1,1,0},
        {1,0,0,0,0},
        {1,1,2,1,0}
      };

bool left(int m[][5],int x,int y)
{
  
  if(y-1<0)
  return false;
  
  if(m[x][y-1]==1)
  return false;
  
  return true;
}

bool right(int m[][5],int x,int y)
{
  
  if(y+1>4)
  return false;
  
  if(m[x][y+1]==1)
  return false;
  
  return true;
}

bool up(int m[][5],int x,int y)
{
  
  if(x-1<0)
  return false;
  
  if(m[x-1][y]==1)
  return false;
  
  return true;
}

bool down(int m[][5],int x,int y)
{
  
  if(x+1>4)
  return false;
  
  if(m[x+1][y]==1)
  return false;
  
  return true;
}

String solve(int m[][5],int x,int y,String temp,int hash)
{
  
  //cout<<x<<" "<<y<<" "<<temp<<endl;
  
  if(m[x][y]==2)
  {
    
    //modified
    if(s>temp)
    {
      s = temp;     //replace with a string later to store the path
      //cout<<s<<endl;  
    }
    return s;
  }
  
  if(s.length()<=temp.length())
  {
    return s;
  }
  
  //cout<<x<<" "<<y<<" "<<temp<<endl;
  
  //LEFT
  switch(abs(hash))
  {
    case 0: if(left(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y-1,temp + "4",(hash-1)%4);
          m[x][y] = 0;
        }
        break;
    case 1: if(down(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x+1,y,temp + "1",(hash-1)%4);
          m[x][y] = 0;
        }
        break;
    case 2: if(right(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y+1,temp + "2",(hash-1)%4);
          m[x][y] = 0;
        }
        break;
    case 3: if(up(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x-1,y,temp + "3",(hash-1)%4);
          m[x][y] = 0;
        }
        break;
  }
  
  //UP
  switch(abs(hash))
  {
    case 0: if(up(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x-1,y,temp + "3",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 1: if(left(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y-1,temp + "4",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 2: if(down(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x+1,y,temp + "1",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 3: if(right(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y+1,temp + "2",(hash)%4);
          m[x][y] = 0;
        }
        break;
  }
  
  //RIGHT
  switch(abs(hash))
  {
    case 0: if(right(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y+1,temp + "2",(hash+1)%4);
          m[x][y] = 0;
        }
        break;
    case 1: if(up(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x-1,y,temp + "3",(hash+1)%4);
          m[x][y] = 0;
        }
        break;
    case 2: if(left(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y-1,temp + "4",(hash+1)%4);
          m[x][y] = 0;
        }
        break;
    case 3: if(down(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x+1,y,temp + "1",(hash+1)%4);
          m[x][y] = 0;
        }
        break;
      
  }
  
  //DOWN
  switch(abs(hash))
  {
    case 0: if(down(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x+1,y,temp + "1",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 1: if(right(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y+1,temp + "2",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 2: if(up(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x-1,y,temp + "3",(hash)%4);
          m[x][y] = 0;
        }
        break;
    case 3: if(left(m,x,y))
        {
          m[x][y] = 1;
          solve(m,x,y-1,temp + "4",(hash)%4);
          m[x][y] = 0;
        }
        break;

      
  }
  /*
  if(left(m,x,y)
  {
    //should also add the direction of the device to the bool function..
    m[x][y] = 1;
    solve(m,x,y-1,temp + "4");
    m[x][y] = 0;  
  }
  
  if(up(m,x,y))
  {
    m[x][y] = 1;
    solve(m,x-1,y,temp + "3");
    m[x][y] = 0;
  }
  
  if(right(m,x,y))
  {
    m[x][y] = 1;
    solve(m,x,y+1,temp + "2");
    m[x][y] = 0;
  }
  
  if(down(m,x,y))
  {
    m[x][y] = 1;
    solve(m,x+1,y,temp + "1");
    m[x][y] = 0;
  }
  */
  return s;
}
      

void setup() 
{
  Serial.begin(9600);
  
  solve(matrix,4,4,temp,0);
  
  Serial.println(s);
}

void loop() 
{

}
