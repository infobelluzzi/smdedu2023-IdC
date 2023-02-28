var cacheName = 'pwa-dashboard';
var filesToCache = [
'/broker/dashboard/index.html'
];
/*
var filesToCache = [
'/broker/dashboard/',
'/broker/dashboard/index.html',
'/broker/dashboard/css/stylesheet.css',
'/broker/dashboard/images/pwa-logo.svg',
'/broker/dashboard/js/core.js'
];
*/ 
/* Avvia il Service Worker e Memorizza il contenuto nella cache */
self.addEventListener('install', function(e) {
    e.waitUntil(
        caches.open(cacheName).then(function(cache) {
            return cache.addAll(filesToCache);
        })
    );
}); 
/* Serve i Contenuti Memorizzati quando sei Offline */
self.addEventListener('fetch', function(e) {
    e.respondWith(
        caches.match(e.request).then(function(response) {
            return response || fetch(e.request);
        })
    );
});