# Markdown - sníða texta

Þú þarft ekki að vera serfræðingur til að skrifa efni. Það er alltaf í lagi að einbeita sér að innihaldinu, einhver í hópnum getur lagað sniðið síðar. En ef þú vilt prófa, þá er hér stuttur leiðarvísir í nokkrum erfiðleika skrefum.

---

## **lvl 0** — Skrifa bara texta

Þetta er bara venjulegur texti.

```text
Engin sérstök uppsetning – bara beinn texti.
Það virkar samt og einhver getur lagað sniðið síðar.
```

---

## **LVL 1** - Grunnatriði

### **Fyrirsagnir**

```markdown
# Fyrirsögn 1

## Fyrirsögn 2

### Fyrirsögn 3
```

# Fyrirsögn 1

## Fyrirsögn 2

### Fyrirsögn 3

### **Punktalistar**

```markdown
- Eitt atriði
- Annað atriði
  - Undiratriði
```

- Eitt atriði
- Annað atriði
  - Undiratriði

### **Númeraðir listar**

```markdown
1. Fyrsta atriði
2. Annað atriði
```

3. Fyrsta atriði
4. Annað atriði

---

## **LVL 2** - Hlekkir og myndir

### **Hlekkir**

```markdown
[Fab Lab Ísland](https://fablab.is)
```

→ [Fab Lab Ísland](https://fablab.is)

### **Myndir**

```markdown
![lýsing](myndaskra.png)
```

- Geymdu myndina í sömu möppu og .md skráin eða í `docs/assets/img`.
- Gott er þjappa myndina svo hún verði undir 500 kb

---

## **lvl 3** — Áherslur, kóði og skipulag

### **Áherslur**

```markdown
_skáletrað_  
**feitletrað**  
`kóðadæmi`
```

_skáletrað_  
**feitletrað**  
`kóðadæmi`

### **Kóðablokkir**

```bash
git commit -m "Fín uppfærsla"
```

---

## **lvl 4** — MkDocs Material snið og aukamöguleikar

[MkDocs Material](https://squidfunk.github.io/mkdocs-material/reference/)

### **Athugasemdir og upplýsingakassar**

```markdown
!!! note
Þetta er góður punktur.
```

!!! note
Þetta er góður punktur.

### **Tákn og merkingar (Material Icons)**

```markdown
:material-lightbulb: Hugmynd!
:material-check: Verkefni lokið
```

:material-lightbulb: Hugmynd!

:material-check: Verkefni lokið

**Sjá lista yfir öll tákn hér:** [Material Icons](https://squidfunk.github.io/mkdocs-material/reference/icons-emojis/)

### **Tafla**

```markdown
| Verkefni               | Staa         |
| ---------------------- | ------------ |
| Að bæta við síðu       | ✅ Lokið     |
| Markdown leiðbeiningar | ⏳ Í vinnslu |
```

| Verkefni               | Staa         |
| ---------------------- | ------------ |
| Að bæta við síðu       | ✅ Lokið     |
| Markdown leiðbeiningar | ⏳ Í vinnslu |

### **Samfallanlegir kaflar (collapsible sections)**

```markdown
??? example "Smelltu til að sjá dæmi"

    Þetta er falinn texti sem hægt er að opna og loka.
```

??? example "Smelltu til að sjá dæmi"

    Þetta er falinn texti sem hægt er að opna og loka.

---

[Á markdownguide.org er fræabær síða sem hægt að fræðast meira um Markdown](https://www.markdownguide.org/)
