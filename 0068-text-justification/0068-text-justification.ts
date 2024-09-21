function fullJustify(words: string[], maxWidth: number): string[] {
    const ans: string[] = [];
    
    for (let i = 0; i < words.length; ) {
        const { lineWords, totalLength } = gatherWords(words, i, maxWidth);
        i += lineWords.length;
        ans.push(formatLine(lineWords, totalLength, maxWidth, i === words.length));
    }
    
    return ans;
}

function gatherWords(words: string[], start: number, maxWidth: number): { lineWords: string[], totalLength: number } {
    const lineWords: string[] = [];
    let totalLength = 0;

    while (start < words.length && totalLength + words[start].length + lineWords.length <= maxWidth) {
        lineWords.push(words[start]);
        totalLength += words[start].length;
        start++;
    }

    return { lineWords, totalLength };
}

function formatLine(lineWords: string[], totalLength: number, maxWidth: number, isLastLine: boolean): string {
    if (lineWords.length === 1 || isLastLine) {
        return lineWords.join(' ') + ' '.repeat(maxWidth - (totalLength + (lineWords.length - 1)));
    }

    const spaceWidth = maxWidth - totalLength;
    const spaceBetweenWords = Math.floor(spaceWidth / (lineWords.length - 1));
    const extraSpaces = spaceWidth % (lineWords.length - 1);

    let formattedLine = '';
    for (let i = 0; i < lineWords.length - 1; i++) {
        formattedLine += lineWords[i];
        formattedLine += ' '.repeat(spaceBetweenWords + (i < extraSpaces ? 1 : 0));
    }
    formattedLine += lineWords[lineWords.length - 1];

    return formattedLine;
}