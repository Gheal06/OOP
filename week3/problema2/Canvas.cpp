#include "Canvas.h"
#include <iostream>
Canvas::Canvas(int width,int height){
    this->h=height,this->w=width;
    this->canvas=new char* [height];
    for(int i=0;i<height;i++){
        this->canvas[i]=new char [width+1];
        for(int j=0;j<width;j++)
            this->canvas[i][j]=' ';
    }
}
void Canvas::SetPoint(int x, int y, char ch){
    if(x<0 || x>=this->w || y<0 || y>=this->h) return;
    this->canvas[y][x]=ch;
}
void Canvas::DrawCircle(int x, int y, int ray, char ch){
    for(int i=0;i<this->h;i++){
        for(int j=0;j<this->w;j++){
            int d=(x-j)*(x-j)+(y-i)*(y-i);
            if(d>ray*(ray-1) && d<=ray*(ray+1))
                SetPoint(j,i,ch);
        }
    }
}
void Canvas::FillCircle(int x, int y, int ray, char ch){
    for(int i=0;i<this->h;i++){
        for(int j=0;j<this->w;j++){
            int d=(x-j)*(x-j)+(y-i)*(y-i);
            if(d<=ray*(ray+1))
                SetPoint(j,i,ch);
        }
    }
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch){
    for(int i=top;i<=bottom;i++)
        this->canvas[i][left]=this->canvas[i][right]=ch;
    for(int j=left;j<=right;j++)
        this->canvas[top][j]=this->canvas[bottom][j]=ch;
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch){
    for(int i=top;i<=bottom;i++)
        for(int j=left;j<=right;j++)
            this->canvas[i][j]=ch;
}
int det(int a, int b, int c, int d, int e, int f){
    return (a-e)*(d-f)-(c-e)*(b-f);
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch){
    int minx=std::min(x1,x2),maxx=std::max(x1,x2),miny=std::min(y1,y2),maxy=std::max(y1,y2),dx=maxx-minx,dy=maxy-miny;
    for(int i=std::max(minx,0);i<this->h && i<=maxx;i++){
        for(int j=std::min(miny,0);j<this->w && j<=maxy;j++){
            int d=det(x1,y1,x2,y2,i,j),dist=dx*dx+dy*dy;
            if(d*d*4<dist)
                SetPoint(j,i,ch);
        }
    }
}
void Canvas::Print(){
    for(int i=0;i<this->h;i++)
        std::cout<<this->canvas[i]<<'\n';
}
void Canvas::Clear(){
    for(int i=0;i<this->h;i++)
        for(int j=0;j<this->w;j++)
            this->canvas[i][j]=' ';
}
