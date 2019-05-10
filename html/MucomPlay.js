'use strict';

import Module from './mucom88.js';

const context = new AudioContext();

document.addEventListener('DOMContentLoaded', () => {
    context.audioWorklet.addModule('./MucomProcessor.js').then(() => {
        document.getElementById('btnPlay').addEventListener('click', async (event) => {
            const kernel = new Module.MucomAudioWorkletKernel();
            kernel.initializeMucom();
            const soundGenerator = new AudioWorkletNode(context,
                'mucom-processor',
                {
                    numberOfInputs: 0,
                    numberOfOutputs: 1,
                    outputChannelCount: [2],
                    processorOptions: kernel
                });

            if (context.state !== 'running') {
                await context.resume();
            }

        }, false);
    });
}, false);
