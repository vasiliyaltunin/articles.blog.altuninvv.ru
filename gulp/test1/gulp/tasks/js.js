var gulp = require('gulp');
var concat = require('gulp-concat');
var uglify = require('gulp-uglify');
var rename = require('gulp-rename');
var cache = require('gulp-cache');
var header = require('gulp-header');

var config = require('../config').js;
var pkg = require('../../package.json');

var compress = require('../config').uglify;

//Баннер с копирайтом и версией
var banner = [
	'/**',
	' <%= pkg.name %>' +
	' @author <%= pkg.author %>' +
	' @version v<%= pkg.version %>' +
	' **/'
].join('\n');

function jsFunc() {
	return gulp.src(['source/js/main.js', 'source/js/**/*.js'])
		.pipe(concat('app.js'))
		.pipe(gulp.dest(config.dest))
		.pipe(rename({ suffix: '.min' }))
		.pipe(cache(uglify(compress.settings)))
		.pipe(header(banner, { pkg: pkg }))
		.pipe(gulp.dest(config.dest))
}

exports.jsTask = jsFunc;