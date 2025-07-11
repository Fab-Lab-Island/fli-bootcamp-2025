# Embroidery and Inkstitch

## English

This page is dedicated to going over some of the embroidery techniques that were used in Húsavík.

[Inkstitch Install Link](https://inkstitch.org/docs/install/)

### Youtube tutorial for Inkstitch

These are the tutorials I watch to get used to using inkstitch. They cover the basics, but there is a lot that can be done with this program. The [Basic Tutorial](https://www.youtube.com/watch?v=W7u4mPaRjIs) teaches how to setup inkscape and inkstitch. It also covers how inkstitch work from a basic level. The [Fill Stitch Tutorial](https://www.youtube.com/watch?v=a3-qerPiJy4) covers how to do a fill stitch with Inkstitch and also the parameters. It also goes over the different type of fill stitch. The [Satin Stitch Tutorial](https://www.youtube.com/watch?v=Sqy_QTgPYH4) show you how to cover lines into satin stitch. It also talks about the parameters. 

### Inkstitch Basic Principles

- Inkstitch .pes file also build from the bottom up. The shape on the lowest on the layer will stitch first and the top object will stitch last. You can alway check how it will stitch by going to → **extensions > ink/stitch > visualize and export > simulator**

- Filled objects are fill stitch by default. 

- Dashed line are a single stitch.

- All texts need to be converted from object to stroke. Also, they sometimes need to be ungrouped. 
→ **path > object to path**

- The way to get satin stitch is to make a stroke on the object. Then convert it to satin.
→ **Extensions > Ink/Stitch > Tools: Satin > Convert Line to Satin**

- Satin line thickness should never be less than 1.5 mm, however 2.0 mm or more is the most ideal.

- Make sure to not save as a .pes file until you are finished with the design and save an .svg as well. It is not easy to open a .pes in inkscape after it has been closed. 

### Test File for Inkstitch

So this is an image of the file before converting the line (stroke) to satin. 

![File before satin conversion.](../assets/img/embroidery/husavik_stitch.jpg)

→ **Extensions > Ink/Stitch > Tools: Satin > Convert Line to Satin**

This is the file after the conversion. 

![File after satin conversion](../assets/img/embroidery/husavik_stitch2.jpg)

It is good to check you work before exporting as a .pes file by using the simulator. → **extensions > ink/stitch > visualize and export > simulator**

[Example of .pes file](../assets/files/embroidery/inkstitch_example.pes) and [Example of .svg file](../assets/files/embroidery/inkstitch_example.svg)

Try these out and let me know how the turn out. I think this is a good starter example to see how inkstitch works by building layer by layer. It also show the basic fill and satin parameters. 

To go further each object can have the parameters changed. → **extensions > ink/stitch > params**


### Improvements to the Machine and Ideas
They are using was a Brother PR680W 6-Needle embroidery machine. [Link to the machine.](https://sewingcraft.brother.eu/en/products/machines/semi-pro-embroidery-machines/semi-pro-embroidery-machines/pr680w)

![Brother Machine](../assets/img/embroidery/PR680W_main.png){loading=lazy}

When using the machine I noticed that the tread area was not labeled. It is need to be able to quickly change trad colors and ensure the machine is treaded correctly. I just cut 1-6 out on the vinyl cutter and then added them to the machine. 

![Numbering on Machine](../assets/img/embroidery/emb_husavik_2.jpg){loading=lazy}

## A Fab Academy project

Ólöf experimented with her fabacademy project with the embdoidery machine and learned about inkstitch. She prepared a Logo which was stitched 3 times with 3 different settings regarding outline, pattern fill and colour swatches. Here are directions on how to prepare a file for embroidering.

### Brochure, directions and download

!!! info "Brochure for Brother 6-needle embroidery machine"
    
    Fab Lab Húsavík has a Brother 6-needle embroidery machine. Here is the [brochure](https://download.brother.com/welcome/doch102285/884t23_om01en.pdf) for the Brother 6-needle embroidery machine. 

!!! tip "A drop of oil before each use"
    
     It is important to put a drop of oil onto the hook before inserting the bobbin case. This has to be done each day that the machine will be used.

![ ](saumavel/W17_OilOnHook.jpg)

!!! info "Download and instructions"
    
    The Inkstitch extension can be downloaded from [here](https://inkstitch.org/docs/install/). 
    
    [Here](https://www.brother-usa.com/products/pr680w?srsltid=AfmBOooVz6D1Qg1xH7Wp5b3vJmmYAfjZst4mKufn2EUSffsu4XYdvi7v) you can find instructions on how to use the machine.

### A design created for the embroidery machine

!!! info "Creating a image for the embroidery machine"
    
     To begin with you open the Inkscape program. Then you can follow the directions [here](https://www.flr.is/_files/ugd/0ebced_1bd42ec7d77140aea1e74aec7377078f.pdf) in a book by Hafey Hallgrímsdóttir on how to create a sticker (the first project in the book). You follow all steps until you have converted an image to a vector drawing. 

     I used a pen drawing that I made but you can also use images from the internet.
     
     Next you click on **Object** and then **Fill and stroke**, turn **Fill** on and turn off **Stroke paint**.
     
     You can either choose a colour for the image there or later, in the embroidery machine.

     Click on **File** and **Document properties**. Then you can see a small button for resizing the page to content.

![ ](saumavel/Bootcamp_Saumavél_ResizeToContent.jpg)


!!! info "Resizing to content"
    
     Now you can see that the page fits around your design.

![ ](saumavel/Bootcamp_saumavél_AfterResizingToContent.jpg)

### Params

!!! info "Looking into params"
    
    If you click on **Extensions**, **Ink/Stitch**, **Params** you can look into the settings for the embroidery.

![ ](saumavel/Bootcamp_s_Params.jpg)

!!! info "Settings and preview params"
    
    In params you can see a preview of the path that will be embroidered. You can also adjust settings.

![ ](saumavel/Bootcamp_s_ParamsSettings.jpg)

### Saving as a .pes file

!!! info "A .pes file generates the sewing path"
    
    In the image below you can see how the .pes file has generated a path for the embroidery machine. You can see how the thread will be laid down.

![ ](saumavel/Bootcamp_s_PesFileFill.jpg)


### Image with only lines

!!! info "Creating a image for the embroidery machine"
    
     If you want to design an image where you are only using lines, you can follow the directions [here](https://www.flr.is/_files/ugd/0ebced_1bd42ec7d77140aea1e74aec7377078f.pdf) in the book by Hafey Hallgrímsdóttir on how to create a sticker but when you have clicked on **Object** and then **Fill and stroke**, turned **Fill** off and turned on **Stroke paint**....then instead of setting the stroke style to 0.02 you make the line thicker, f.ex. 1.5. That is the minimal thickness but the line can be thicker. Then you can either choose a colour for the image there or later, in the embroidery machine.

 ![ ](saumavel/Bootcamp_saumavél_FillAndStroke.jpg)  


!!! info "Converting line to satin"
    
     The next step is to click on **Extensions**, **Ink/Stitch**, **Tools: satin** and then **Convert line to satin**.

![ ](saumavel/Bootcamp_saumavél_ConvertLineToSatin.jpg)

!!! info "Saving as a .pes file"
    
    The next step is to save the file as a **.pes file**. You can choose any colour for the fill in the file and then you can change the colours when adjusting settings in the embroidery machine. 
    
![ ](saumavel/Bootcamp_saumavél_SaveAsPes.jpg)

!!! info "A .pes file generates the sewing path"
    
    In the image below you can see how the .pes file has generated a path for the embroidery machine. You can see how the thread will be laid down.

![ ](saumavel/Bootcamp_saumavél_LineConverted.jpg)

### Fastening material

!!! info "Fastening the material"
    
    In this project a reusable bag was used. The material was fastened in an embroidery frame. The inner frame frame was placed inside the reusable bag and on top of it, also inside the bag, a  stabilizing backing was placed. It is important to make sure that the stabilizing backing is a bit bigger than the frame so that it can fit between the inner frame and the outer frame. After adjusting the placement of the inner frame + the stabilizing backing, the outer frame is placed on top of the reusable bag and pressed down until the frames fit together. Then the screw is tightened to keep the material in place.

![ ](saumavel/Week17_EmbroideryFrameAndStabilizer.jpg)

![ ](saumavel/Week17_Frame1000x750.jpg)

### Arranging layers to control workflow

!!! tip "Arranging the layers"
    
    You can control which layer is stitched first and which layers follow. The machine always begins with the layer at the bottom on the list of layers in Inkscape and then follows the layers upwards. This means that you can arrange the layers if the order of the layers matters. Just drag the layers to arrange them to your preferred setup.

### Using Offset

!!! info "Offsetting"
    
     When I started to document this, I could not remember how to group the letters in the right way to be able to use a function called **Dynamic offset**. I found an answer by Lazur to a question in the [Inkscape forum](https://alpha.inkscape.org/vectors/www.inkscapeforum.com/viewtopic93da.html?t=15368). It is second in line from the top.

     Lazur says that you can use shortcuts. First you can use **Object to path** on a text to turn it into a group of paths. Then you do the following:

     - Press **Shift+Ctrl+C** to convert text to path

     - Press **Shift+Ctrl+G** to group

     - Press **Ctrl+K** to combine paths

     Can you see the tiny, blue diamond handle at the top of the bounding box in the image below? You can now grab it and resize (offset) the whole design.

![ ](saumavel/W17_DynamicOffset700x400.jpg)

### Shortcuts in Inkscape

!!! tip "Shortcuts in Inkscape"
    
     [Here](https://inkscape.org/doc/keys091.html) you can find a list of all shortcuts in Inkscape.

### Aligning

!!! info "Aligning fill and outline"
    
     The outline forms grouped the outline forms together by pressing **Shift+Ctrl+G**. Then I left-clicked on my mouse and dragged over both designs to select all. Then I clicked on **Object** and then **Align and distribute**.

![ ](saumavel/W17_AlignAndDistribute.jpg)

!!! info "Aligning done"
    
     Then you click on the symbols for aligning on the x-axis and the y-axis. Then the two forms will be aligned.

![ ](saumavel/W17_Aligned.jpg)

### Embroidery ready

!!! info "Embroidery ready"
    
     This is what the fill and outline looks like after embroidering. The thickness of the line in a design like this can be adjusted.

![ ](saumavel/Week17_FillAndOutlineReady800x584.jpg)


### Experimenting

Sarah and Alissa tried and failed mission, preparing inkspace file for seeing text in inkstitch. Troubleshoot on written Name in Inkspace when simulating the graphic and text, onlz the logo graphic was visible for stitching simulation/preview.

Ólöf helped us in finding out how to save the svg and pes files for checking the text ifit appears, but that unfortunately did not work. Yout Tube video gave us the hint about inkspace lettering, worked for us to place the text and see it simulated, but did not work to get the right colour and design as prepared beforehands on inkspace. Now, we figured it out, so it will be stitched with the text and the temporary logo for the Textíllab.

Pictures are following.

![saumavel](../assets/img/IMG_6317.jpeg)

## Upplýsingar á íslensku

## Útsaumur og Inkstitch

Ólöf vann að verkefni í Fab Academy og prófaði sig áfram með ,,Extension" í Inskscape sem kallast Inkstitch. Hún teiknaði mynd af hákarli og prófaði sig áfram með þá teikningu. Hún notaði einnig logo til að sjá hvernig hægt væri að nota ,,Offset" svo útlína væri ekki saumuð yfir fyllingu. Hér eru útskýringar á verkferlinu.

### Bæklingur og leiðbeiningar

!!! info "Bæklingur fyrir Brother 6-nála útsaumsvél"
    
    Fab Lab Húsavík á Brother 6-6-nála útsaumsvél. Hér er [bæklingur](https://download.brother.com/welcome/doch102285/884t23_om01en.pdf) fyrir Brother 6-6-nála útsaumsvélina. 

!!! tip "Dropi af olíu áður en unnið er með vélina"
    
     Það er mikilvægt að setja dropa af olíu á krókinn áður en neðri tvinninn er settur í. Þetta borgar sig að gera einu sinni á dag þá daga sem á að vinna með vélina, þ.e. áður en verkið hefst.

![ ](saumavel/W17_OilOnHook.jpg)

!!! info "Niðurhal og leiðbeiningar"
    
    Hægt er að sækja Inkstitch extension [hér](https://inkstitch.org/docs/install/). 
    
    [Hér](https://www.brother-usa.com/products/pr680w?srsltid=AfmBOooVz6D1Qg1xH7Wp5b3vJmmYAfjZst4mKufn2EUSffsu4XYdvi7v) má finna fleiri upplýsingar og leiðbeiningar um vélina.

### Að útbúa mynd fyrir saumavélina

!!! info "Að útbúa mynd fyrir saumavélina"
    
     Byrjaðu á að opna Inkscape. Fylgdu svo leiðbeiningunum [hér](https://www.flr.is/_files/ugd/0ebced_1bd42ec7d77140aea1e74aec7377078f.pdf) í bók eftir Hafey Hallgrímsdóttur um hvernig eigi að búa til límmiða (fyrsta verkefnið í bókinni). Fylgdu öllum leiðbeiningum þar til þú hefur búið til vektor teikningu.

     Ég notaði pennateikningu sem ég gerði en það er líka hægt að nota myndir af netinu.
     
     Næst smellir þú á **Hlutur** og svo **Fylling og útlína**, kveiktu á **Fyllingu** og slökktu á **Lit útlínu**.
     
     Þú getur valið liti hér en þú munt svo stilla litina endanlega í útsaumsvélinni.

     Smelltu á **Skrá** og **Skráareiginleikar**. Þar smellir þú á lítinn hnapp merktan **Aðlaga stærð að innihaldi**.

![ ](saumavel/Bootcamp_Saumavél_ResizeToContent.jpg)


!!! info "Búið að aðlaga stærð að innihaldi"
    
     Eftir að stærðin hefur verið aðlöguð að innihaldi sést að blaðsíðan passar akkúrat utan um verkefnið.

![ ](saumavel/Bootcamp_saumavél_AfterResizingToContent.jpg)


!!! info "Að skoða stillingar í params"
    
    Ef þú smellir á **Extensions**, **Ink/Stitch**, **Params** getur þú skoðað stillingarnar fyrir útsauminn.

![ ](saumavel/Bootcamp_s_Params.jpg)

!!! info "Stillingar og forskoðun í params"
    
    Í params er meðal annars að finna forskoðun á útsaumsverkinu. Það spilast eins og myndband svo það sést hvernig útsaumurinn fer fram. Þarna er líka hægt að breyta ýmsum stillingum.

![ ](saumavel/Bootcamp_s_ParamsSettings.jpg)


!!! info ".pes skrá býr til feril fyrir saumavél"
    
    Á myndinni hér fyrir neðan sést hvernig .pes hefur búið til feril fyrir útsaumsvélina. Þarna sést hvernig tvinninn verður lagður niður.

![ ](saumavel/Bootcamp_s_PesFileFill.jpg)


### Að búa til útlínumynd

!!! info "Að búa til útlínumynd fyrir útsaumsvélina"
    
     Ef þú vilt búa til útlínumynd getur þú fylgt leiðbeiningunum [hér](https://www.flr.is/_files/ugd/0ebced_1bd42ec7d77140aea1e74aec7377078f.pdf) í bókinni eftir Hafey Hallgrímsdóttur um hvernig eigi að búa til límmiða en þegar þú hefur smellt á **Hlutur** og **Fylling og útlína**, slökkt á **Fylling** og kveikt á **Litur útlínu**....þá, í stað þess að stilla **Stíll útlínu** á 0.02 gerir þú línuna þykkari. Það er gott a miða við að hafa línuna að lágmarki 1.5. Svo getur þú valið lit á línuna en þær stillingar eru svo endanlega gerðar í útsaumsvélinni síðar.

 ![ ](saumavel/Bootcamp_saumavél_FillAndStroke.jpg)  


!!! info "Að nota Convert line to Satin"
    
     Næsta skref er að smella á **Extensions**, **Ink/Stitch**, **Tools: satin** og svo **Convert line to satin**.

![ ](saumavel/Bootcamp_saumavél_ConvertLineToSatin.jpg)

!!! info "að vista sem .pes file"
    
    Næst er skráin vistuð sem **.svg** skrá. Þessa skrá er hægt að nota síðar ef það reynist þörf á að breyta hönuninni. Svo er skráin vistuð sem **.pes file**. 
    
![ ](saumavel/Bootcamp_saumavél_SaveAsPes.jpg)

!!! info ".pes skrá býr til útsaumsferilinn"
    
    Á myndinni hér fyrir neðans sést hvernig .pes skráin bjó til feril fyrir þetta verkefni. Þráðurinn sést vel.

![ ](saumavel/Bootcamp_saumavél_LineConverted.jpg)

### Að festa efnið á ramma

!!! info "Að festa efnið"
    
    Margnota taupoki var notaður í þetta verkefni. Efnið var fest í sérstakan útsaumsramma. Innri hluti útsaumsrammans var lagður innan í taupokann. Svo var bútur af stuðningsefni lagður ofan á rammann, semsagt einnig inni í pokanum. Það er mikilvægt að búturinn af stuðningsefninu sé nógu stór til að geta fallið á milli innri rammans og ytri rammans. Eftir að búið er að stilla af staðsetninguna á innri rammanum+stuðningsefninu er ytri ramminn lagður ofan á efnið og honum þrýst niður þannig að hann falli utan um innri rammann sem er hinum megin við efnið. Svo er skrúfan hert til að halda efninu á sínum stað. Þess er gætt að efnið sé nógu vel strekkt til að hægt sé að banka létt á efnið eins og trommu.

![ ](saumavel/Week17_EmbroideryFrameAndStabilizer.jpg)

![ ](saumavel/Week17_Frame1000x750.jpg)


!!! tip "Röðun á lögum ræður röðun á útsaumi"
    
    Þegar unnið er með fleiri en einn litaflöt og línur í Inkscape verða til nokkur lög (e. layers) í Inkscape. Það er hægt að stýra því á hvaða litafleti vélin byrjar. Vélin byrjar ávallt á því lagi sem er neðst á listanum í Inkscape og fylgir svo lögunum uppávið. Þetta þýðir að þú getur breytt röðun laganna ef það skiptir máli í hvaða röð saumað er. Dragðu bara lögin til þar til röðunin er eins og óskað er eftir.

### Að nota Offset

!!! info "Að nota Offset"
    
     Þegar ég byrjaði að skrá þetta niður mundi ég ekki hvernig ætti að hópa bókstafi saman á réttan hátt til að geta notað svokallað **Dynamic offset**. Ég fann svar frá einstaklingi, Lazur að nafni, við spurningu á [Inkscape forum](https://alpha.inkscape.org/vectors/www.inkscapeforum.com/viewtopic93da.html?t=15368). Svarið er annað í röðinni ofan frá.

     Lazur segir að það sé hægt að nota flýtileiðir. Eftirfarandi skrefum er fylgt:

     - Ýttu á **Shift+Ctrl+C** til að breyta texta í feril

     - Ýttu á **Shift+Ctrl+G** til að ferlarnir verði saman í hópi

     - Ýttu á **Ctrl+K** til að sameina ferla

     Sérðu pínulitla, bláa demantinn/tígulinn ofarlega í hönnuninni á myndinni hér fyrir neðan? Nú er hægt að grípa hann og draga hann til þannig að hönnunin minnki öll eða stækki (offset).

![ ](saumavel/W17_DynamicOffset700x400.jpg)

### Flýtileiðir í Inkscape

!!! tip "Flýtileiðir í Inkscape"
    
     [Hér](https://inkscape.org/doc/keys091.html) er að finna lista yfir allar flýtileiðir í Inkscape.

### Að jafna og dreifa

!!! info "Að jafna og dreifa"
    
     Ýttu á **Shift+Ctrl+G** til að ná öllum útlínuformunum saman í hóp. Veldu svo öll form í skjalinu með því að vinstrismella á músina og draga hana yfir allt. Svo er smellt á **Hlutur** og svo **Jafna og dreifa**.

![ ](saumavel/W17_AlignAndDistribute.jpg)

!!! info "Jöfnun og dreifing framkvæmd"
    
     Svo er smellt á táknin fyrir það að jafna á x-ás og y-ás. Þá er búið að staðsetja þau jafnt saman.

![ ](saumavel/W17_Aligned.jpg)

### Útsaumur tilbúinn

!!! info "Útsaumur tilbúinn"
    
     Svona leit verkefnið út eftir að vélin saumaði það út. Athugið að það er hægt að nota misþykkar útlínur í svona verkefnum, allt eftir smekk hvers og eins.

![ ](saumavel/Week17_FillAndOutlineReady800x584.jpg)


