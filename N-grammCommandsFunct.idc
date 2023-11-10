auto f=fopen("e:\\temp\\commands_from_exe.txt","w");

auto a,Fstart,tmp,prev;
a=NextHead(0,BADADDR);
while(a!=BADADDR){
    if(isCode(GetFlags(a))){
    if (PrevFunction(a)==BADADDR){
        prev=NextHead(0,BADADDR);
    }else{prev=PrevFunction(a);}
    Fstart=NextFunction(prev);
    
    if (FindFuncEnd(a)-Fstart<7){
        a=NextHead(a,BADADDR);
        continue;
    }
    if (
        (a==Fstart)&&("push"==GetMnem(a)) ){
    a=NextHead(a,BADADDR);    
    a=NextHead(a,BADADDR);
    }
    
    
        //fprintf(f,"%s %s %s %s +\n", atoa(a), GetMnem(a), GetOpnd(a,0),GetOpnd(a,1));
        fprintf(f,"%s %s %s +\n", GetMnem(a), GetOpnd(a,0),GetOpnd(a,1));

        if (NextHead(a,BADADDR)==FindFuncEnd(a)){
                fprintf(f,"***\n");
        }
    }
    a=NextHead(a,BADADDR);
}
Message("ok\n");
fclose(f);