bool judgeCircle(char* moves) {
    int ver = 0;
    int hir = 0;
    int len = strlen(moves);
    for(int i = 0; i < len; i++)
    {
        switch(moves[i]){
            case 'L': ver++;continue;
            case 'R': ver--;continue;
            case 'D': hir--;continue;
            case 'U': hir++;continue;
        }
        i++;
    }
    if(ver == 0 && hir == 0) return true;
    return false;
}
