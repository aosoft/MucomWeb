# MUCOM MML - Basic intro

**Play codes in sandbox**:
https://aosoft.github.io/MucomWeb.Play/

## Example 1

**Code example**:
> A t210 @45000 o2 v15  [ d4 d4 d4 ] 1

**Code explanation**:

`A ` -> FM Channel 1

`t210 ` -> time or speed

`@45000`  -> sample, tone or timbre

`o1` -> octave

`v15` - volume 0-15

`[ d ]` -> musical note

`[ d4 ] `-> note and note duration

`[ d4 d4 d4 ]` -> sequence of notes

`] 1` -> number of repetitions of this sequence


**Others codes**:

` r or .` -> rest, break or blank

`>` -> go up 1 octave

`<<` -> go down 2 octaves
 
## Example 2

**Code example single channel: DO RE MI FA**

> A t210 @0199 o2 v15  [ c4 d4 e4 f2 f8 f2 c4 d4 c4 d2 d8 d2 ] 1

> A t210 @0199 o2 v15  [ c4 g4 f4 e2 e8 e2 c4 d4 e4 f2 f8 f2 ] 1

## Example 3

**Code example: Channel A and Channel B**
```
A t210 @0199 o2 v15  [ c4 d4 e4 f2 f8 f2 c4 d4 c4 d2 d8 d2 ] 1
B t210 @0199 o4 v15  [ c4 d4 e4 f2 f8 f2 c4 d4 c4 d2 d8 d2 ] 1

A t210 @0199 o2 v15  [ c4 g4 f4 e2 e8 e2 c4 d4 e4 f2 f8 f2 ] 1
B t210 @0199 o4 v15  [ c4 g4 f4 e2 e8 e2 c4 d4 e4 f2 f8 f2 ] 1
```

## Example 4

**Code example: MARIO**
 
> A t195 @0199 o4 v15 [ e16e8e8c16e8g2c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b8.>c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b4&b16>g16f+16f16d+8e8<g+16a16>c8<a16>c16d8.g16f+16f16d+8e8>c8c16c4.<g16f+16f16d+8e8<g+16a16>c8<a16>c16d8.d+8.d8.c2&c8g16f+16f16d+8e8<g+16a16>c8<a16>c16d8.g16f+16f16d+8e8>c8c16c4  ] 1
> 
> A t180 @0199 o4 v15[g16f+16f16d+8e8<g+16a16>c8<a16>c16d8.d+8.d8.c2c16c8c8c16d8e16c8<a16g4>c16c8c8c16d16e2&e16c16c8c8c16d8e16c8<a16g4>e16e8e8c16e8g2c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b8.>c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b8.>e16c8<g8.g+8a16>f8f16<a4b16.>a16a16.a16.g16f16.e16c8<a16g4>e16c8<g8.g+8a16>f8f16<a4b16>f8f16f16.e16d16.c2e16c8<g8.g+8a16>f8f16<a4b16.>a16a16.a16.g16f16.e16c8<a ] 1
> 
> A t180 @0199 o4 v15[g16f+16f16d+8e8<g+16a16>c8<a16>c16d8.d+8.d8.c2c16c8c8c16d8e16c8<a16g4>c16c8c8c16d16e2&e16c16c8c8c16d8e16c8<a16g4>e16e8e8c16e8g2c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b8.>c8.<g8.e8.a8b8a+16a8g16.>e16g16.a8f16g8e8c16d16<b8.>e16c8<g8.g+8a16>f8f16<a4b16.>a16 ] 1 
> 
> A t180 @0199 o4 v15[ a16.a16.g16f16.e16c8<a16g4>e16c8<g8.g+8a16>f8f16<a4b16>f8f16f16.e16d16.c2e16c8<g8.g+8a16>f8f16<a4b16.>a16a16.a16.g16f16.e16c8<a16g4>e16c8<g8.g+8a16>f8f16<a4b16>f8f16f16.e16d16.c2c16c8c8c16d8e16c8<a16g4>c16c8c8c16d16e2&e16c16c8c8c16d8e16c8<a16g4>e16e8e8c16e8g2e16c8<g8.g+8a16>f8f16<a4b16.>a16a16.a16.g16f16.e16c8<a16g4>e16c8<g8.g+8a16>f8f16<a4b16>f8f16f16.e16d16.c3 ] 1 
>  

Obs.: I divided it into smaller parts so as not to burst memory and crash the browser


## References

**Mario MML code**
https://archeagemmllibrary.com/super-mario/


**MUCOM MML** **- only in japanese**

https://github.com/onitama/mucom88/wiki/MMLリファレンス#-基本的なmmlの書き方
